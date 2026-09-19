// Smoke test for AutomaticCalender (src/Main/src/main.cpp).
//
// This project has no test target anywhere in its CMakeLists.txt files (no
// enable_testing()/add_test() call exists), so there was nothing for the
// previous workflow's `ctest` step to run. This test exercises the same
// class the shipped main() does, without touching that translation unit's
// own entry point: `main` is renamed away with a macro for the duration of
// the #include, then restored so this file's own main() is the one that
// runs.
#include <cassert>
#include <iostream>

#define main disabled_program_entry_point
#include "../src/Main/src/main.cpp"
#undef main

int main() {
    AutomaticCalender calendar;

    // 2020-05-03 was a Sunday. src/Consts/include/consts.h's `week` table
    // puts Sunday at index 0, matching document/蔡勒公示.md's convention
    // that Zeller's congruence returns w=0 for Sunday.
    assert(calendar.getThisDayWeekString(2020, 5, 3) == "日");

    // 2020 is a leap year (divisible by 4, not by 100), so February must
    // have 29 days per src/Consts/include/consts.h's leapYearMonth table.
    Month *february = calendar.getThisMonthCalenderStruct(2020, 2);
    assert(february->data.length == 29);

    std::cout << "smoke test passed" << std::endl;
    return 0;
}
