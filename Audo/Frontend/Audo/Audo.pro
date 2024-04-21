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
    requests.cpp \
    signin.cpp

HEADERS += \
    MainPage.h \
    SignUp.h \
    StudentSignUp.h \
    TeacherSignUp.h \
    account.h \
    audo.h \
    class.h \
    netConfig.h \
    requests.h \
    signin.h \
    user.h

FORMS += \
    MainPage.ui \
    SignUp.ui \
    StudentSignUp.ui \
    TeacherSignUp.ui \
    account.ui \
    audo.ui \
    requests.ui \
    signin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
