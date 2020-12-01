TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        airport.cpp \
        application.cpp \
        database.cpp \
        driver.cpp \
        htmldriver.cpp \
        main.cpp \
        ticket.cpp \
        ticket_window.cpp \
        ticketbase.cpp \
        txtdriver.cpp \
        ui.cpp

HEADERS += \
    airport.h \
    application.h \
    database.h \
    driver.h \
    htmldriver.h \
    ticket.h \
    ticket_window.h \
    ticketbase.h \
    txtdriver.h \
    ui.h
