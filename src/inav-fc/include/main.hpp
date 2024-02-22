#include <Client.hpp>
#include <iostream>
#include <msp_msg.hpp>

struct SubCallbacks {
    void onIdent(const msp::msg::Ident& ident) { std::cout << ident; }

    void onStatus(const msp::msg::Status& status) { std::cout << status; }

    void onImu(const msp::msg::RawImu& imu) {
        std::cout << msp::msg::ImuSI(
            imu, 512.0, 1.0 / 4.096, 0.92f / 10.0f, 9.80665f);
    }

    void onServo(const msp::msg::Servo& servo) { std::cout << servo; }

    void onMotor(const msp::msg::Motor& motor) { std::cout << motor; }

    void onRc(const msp::msg::Rc& rc) { std::cout << rc; }

    void onAttitude(const msp::msg::Attitude& attitude) {
        std::cout << attitude;
    }

    void onAltitude(const msp::msg::Altitude& altitude) {
        std::cout << altitude;
    }

    void onAnalog(const msp::msg::Analog& analog) { std::cout << analog; }

    void onRcTuning(const msp::msg::RcTuning& rc_tuning) {
        std::cout << rc_tuning;
    }

    void onPID(const msp::msg::Pid& pid) { std::cout << pid; }

    void onBox(const msp::msg::ActiveBoxes& box) { std::cout << box; }

    void onMisc(const msp::msg::Misc& misc) { std::cout << misc; }

    void onMotorPins(const msp::msg::MotorPins& motor_pins) {
        std::cout << motor_pins;
    }

    void onBoxNames(const msp::msg::BoxNames& box_names) {
        std::cout << box_names;
    }

    void onPidNames(const msp::msg::PidNames& pid_names) {
        std::cout << pid_names;
    }

    void onBoxIds(const msp::msg::BoxIds& box_ids) { std::cout << box_ids; }

    void onServoConf(const msp::msg::ServoConf& servo_conf) {
        std::cout << servo_conf;
    }

    void onDebugMessage(const msp::msg::DebugMessage& debug_msg) {
        std::cout << "#Debug message:" << std::endl;
        std::cout << debug_msg.debug_msg << std::endl;
    }

    void onDebug(const msp::msg::Debug& debug) { std::cout << debug; }
};

static bool running = true;

void onExit(int /*signal*/) { running = false; }