*** Settings ***
Library    SerialLibrary

*** Variables ***
${PORT}    COM4        # Change this to your actual serial port
${BAUD}    115200      # Set this to match STM32 UART baud rate

*** Test Cases ***
Connect To DAQ
    Open Serial Connection    ${PORT}    ${BAUD}
    Sleep    1s

Read Temperature
    Write    GET TEMP\n
    ${resp}=    Read Until    C\n
    Log    ${resp}
    Should Contain    ${resp}    TEMP:

Read Pressure
    Write    GET PRESSURE\n
    ${resp}=    Read Until    psi\n
    Log    ${resp}
    Should Contain    ${resp}    PRESSURE:

Disconnect
    Close Serial Connection
