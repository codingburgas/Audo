QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SignUp.cpp \
    StudentSignUp.cpp \
    TeacherSignUp.cpp \
    account.cpp \
    audo.cpp \
    main.cpp \
    MainPage.cpp \
    signin.cpp \
    studentgrades.cpp \
    teacheraccount.cpp \
    teachergrades.cpp

HEADERS += \
    MainPage.h \
    SignUp.h \
    StudentSignUp.h \
    TeacherSignUp.h \
    account.h \
    audo.h \
    class.h \
    handler.h \
    signin.h \
    studentgrades.h \
    teacheraccount.h \
    teachergrades.h \
    utils.h
    user.h

FORMS += \
    MainPage.ui \
    SignUp.ui \
    StudentSignUp.ui \
    TeacherSignUp.ui \
    account.ui \
    audo.ui \
    signin.ui \
    studentgrades.ui \
    teacheraccount.ui \
    teachergrades.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

INCLUDEPATH += $$PWD/../../../vendor/cpr/curl/include
DEPENDPATH += $$PWD/../../../vendor/cpr/curl/include

INCLUDEPATH += $$PWD/../../../vendor/cpr/include
DEPENDPATH += $$PWD/../../../vendor/cpr/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../vendor/cpr/libs/Release-libs/ -llibcurl-d_imp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../vendor/cpr/libs/Debug-libs/ -llibcurl-d_imp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../vendor/cpr/libs/Release-libs/ -lcpr
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../vendor/cpr/libs/Debug-libs/ -lcpr
