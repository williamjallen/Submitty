"""Migration for a given Submitty course database."""


def up(config, database, semester, course):
    database.execute("ALTER TABLE polls ADD COLUMN IF NOT EXISTS results_visible BOOLEAN")
    database.execute("ALTER TABLE polls ADD COLUMN IF NOT EXISTS answers_visible BOOLEAN")
    database.execute("ALTER TABLE polls ADD COLUMN IF NOT EXISTS results_visible_during_poll BOOLEAN")
    database.execute("ALTER TABLE polls ADD COLUMN IF NOT EXISTS answers_visible_during_poll BOOLEAN")


def down(config, database, semester, course):
    pass
