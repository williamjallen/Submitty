<?php

declare(strict_types=1);

namespace app\controllers\calendar;

use app\controllers\AbstractController;
use app\controllers\GlobalController;
use app\libraries\routers\AccessControl;
use app\libraries\response\JsonResponse;
use app\libraries\response\WebResponse;
use app\libraries\response\MultiResponse;
use app\models\Course;
use app\models\gradeable\Gradeable;
use app\models\gradeable\GradeableList;
use app\models\User;
use app\views\calendar\CalendarView;
use Exception;
use Symfony\Component\Routing\Annotation\Route;

class CalendarController extends AbstractController {
    private $gradeables = [];

    /**
     * Loads from the database of all courses and get all gradeables information. Only load once unless the user
     * refreshes the page.
     *
     * @param null $user_id
     */
    private function loadFromDB($user_id = null) {
        $user = $this->core->getUser();
        if (is_null($user_id) || $user->getAccessLevel() !== User::LEVEL_SUPERUSER) {
            $user_id = $user->getId();
        }

        // Load the gradeable information for each course
        $courses = $this->core->getQueries()->getCourseForUserId($user_id);
        foreach ($courses as $course) {
            /** @var Course $course */
            try {
                $this->core->loadCourseConfig($course->getSemester(), $course->getTitle());
                $this->core->loadCourseDatabase();
                foreach ($this->core->getQueries()->getGradeableConfigs(null) as $gradeable) {
                    /** @var Gradeable $gradeable */
                    $this->gradeables["{$course->getSemester()}||{$course->getTitle()}||{$gradeable->getId()}"] = $gradeable;
                }
                $this->core->getCourseDB()->disconnect();
            }
            catch (Exception $e) {
            }
        }
        $this->core->getConfig()->setCourseLoaded(false);
    }

    /**
     * This function loads the gradeable information from all courses, and list them on a calendar. The calendar is
     * accessible through the side bar button in a global scope
     *
     * @Route("/calendar")
     *
     * @param string|null $user_id
     * @return MultiResponse
     * @throws Exception if a Gradeable failed to load from the database
     * @see GlobalController::prep_user_sidebar
     */
    public function viewCalendar($user_id = null): MultiResponse {
        if ($this->gradeables == []) {
            $this->loadFromDB($user_id);
        }
        $gradeable_list = new GradeableList($this->core, null, $this->gradeables);

        return new MultiResponse(
            JsonResponse::getSuccessResponse($gradeable_list->getGradeablesBySection()),
            new WebResponse(CalendarView::class, 'showGradeableCalendar', $gradeable_list)
        );
    }
}