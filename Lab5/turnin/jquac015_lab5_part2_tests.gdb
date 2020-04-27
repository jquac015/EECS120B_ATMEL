# Test file for "Lab5"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "PINA: 0xFF ==> PORTC: 0x00, state: STANDBY"
set Counter_State = Start
setPINA 0xFF
continue 2
expectPORTC 0x00
expect Counter_State STANDBY
checkResult

test "PINA: 0x7C ==> PORTC: 0x00, state: RESET"
setPINA 0x7C
continue 2
expectPORTC 0x00
expect Counter_State RESET
checkResult

test "PINA: 0xF8 ==> PORTC: 0x00, state: RESET"
setPINA 0xF8
continue 2
expectPORTC 0x00
expect Counter_State RESET
checkResult

test "PINA: 0xFE ==> PORTC: 0x00, state: RESET"
setPINA 0xFE
continue 2
expectPORTC 0x00
expect Counter_State RESET
checkResult

test "PINA: 0xFE ==> PORTC: 0x00, state: RESET"
setPINA 0xFE
continue 2
expectPORTC 0x00
expect Counter_State RESET
checkResult

test "PINA: 0xFF ==> PORTC: 0x00, state: STANDBY"
setPINA 0xFF
continue 2
expectPORTC 0x00
expect Counter_State STANDBY
checkResult

test "PINA: 0xFF ==> PORTC: 0x00, state: STANDBY"
setPINA 0xFF
continue 2
expectPORTC 0x00
expect Counter_State STANDBY
checkResult

test "PINA: 0xFD ==> PORTC: 0x00, state: DEC"
setPINA 0xFD
continue 2
expectPORTC 0x00
expect Counter_State STANDBY
checkResult


# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
