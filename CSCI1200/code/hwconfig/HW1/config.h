/* Copyright (c) 2014, Chris Berger, Jesse Freitas, Severin Ibarluzea,
Kiana McNellis, Kienan Knight-Boehm, Sam Seng

All rights reserved.
This code is licensed using the BSD "3-Clause" license. Please refer to
"LICENSE.md" for the full license.
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "../../rcos/SCRIPTS/TestCase.h"
//#include "GradingRubric.h"

const std::string id = "HW1";
const std::string name = "Text Justification";
const std::string due_date = "2014-05-15 11:59:59.0";

// Compile Command (executed in student FILES directory)
const std::string compile_command = "g++ -g *.cpp";

// Submission parameters
const int max_submissions = 20;
const int submission_penalty = 5;

// Compile-time parameters
const int max_clocktime = 2;		// in seconds
const int max_cputime = 2;			// in seconds
const int max_output_size = 100;	// in KB
	// OTHERS?

// Grading parameters
const int total_pts = 50;
const int auto_pts = 30;
const int readme_pts = 2;
const int compile_pts = 3;
const int ta_pts = 20;

// File directories

// input files directory
const char* input_dir = "../../CSCI1200/testingInput/HW1";
// expected output files directory
const char* expected_out_dir = "../../CSCI1200/Scripts/expectedOutput/HW1/";

// Test cases
const int num_testcases = 11;

TestCase testcases[11] {

/************* README AND COMPILATION *****************/

TestCase(
	"Readme",
	"",
	"",
	"README.txt",
	"",
	"",
	readme_pts,				// points for readme
	false,
	false,
	DONT_CHECK,
	DONT_CHECK,
	false,
	"",
	NULL
),
TestCase(
	"Compilation",
	"",
	"",
	"a.out",		// name of .exe created by student
	"",
	"",
	compile_pts,				// points for compilation
	false,
	false,
	DONT_CHECK,
	DONT_CHECK,
	false,
	"",
	NULL
),

/******************** TEST CASES **********************/
TestCase(
	"left justify example",							// title
	"./justify.exe example.txt output.txt 16 flush_left",						// details
	"./a.out example.txt test1_out.txt 16 flush_left",	// command
	"test1_out.txt",					// output file name [V]
	"Expected output.txt",					// output file description
	"example_16_flush_left.txt",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar				// compare function [V]
),
TestCase(
	"right justify example",							// title
	"./justify.exe example.txt output.txt 16 flush_right",						// details
	"./a.out example.txt test2_out.txt 16 flush_right",	// command
	"test2_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"example_16_flush_right.txt",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar				// compare function [V]
),
TestCase(
	"full justify example",							// title
	"./justify.exe example.txt output.txt 16 full_justify",						// details
	"./a.out example.txt test3_out.txt 16 full_justify",	// command
	"test3_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"example_16_full_justify.txt",				// expected output file [V]
	4,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"left justify gettysburg address",							// title
	"./justify.exe gettysburg_address.txt output.txt 16 flush_left",						// details
	"./a.out gettysburg_address.txt test4_out.txt 16 flush_left",	// command
	"test4_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"gettysburg_address_70_flush_left.txt",				// expected output file [V]
	2,									// points [V]
	true,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"right justify gettysburg address",							// title
	"./justify.exe gettysburg_address.txt output.txt 70 flush_right",						// details
	"./a.out gettysburg_address.txt test5_out.txt 70 flush_right",	// command
	"test5_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"gettysburg_address_70_flush_right.txt",				// expected output file [V]
	2,									// points [V]
	true,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"full justify gettysburg address",							// title
	"./justify.exe gettysburg_address.txt output.txt 70 full_justify",	// details
	"./a.out gettysburg_address.txt test6_out.txt 70 full_justify",	// command
	"test6_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"gettysburg_address_70_full_justify",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"full justify long word",							// title
	"./justify.exe long_word.txt output.txt 15 full_justify",	// details
	"./a.out long_word.txt test7_out.txt 15 full_justify",	// command
	"test7_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"long_word_15_full_justify.txt",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"lengthier document",							// title
	"./justify.exe lengthier.txt output.txt 15 full_justify",	// details
	"./a.out lengthier.txt test8_out.txt 15 full_justify",	// command
	"test8_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"expected_test8.txt",				// expected output file [V]
	3,									// points [V]
	true,								// hidden [V]
	true,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	" lots of long words",							// title
	"./justify.exe lots_long.txt output.txt 15 full_justify",	// details
	"./a.out lots_long.txt test9_out.txt 15 full_justify",	// command
	"test9_out.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"expected_test9.txt",				// expected output file [V]
	2,									// points [V]
	true,								// hidden [V]
	true,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
)
};

TestCase* readmeTestCase = &testcases[0];
TestCase* compileTestCase = &testcases[1];

#endif
