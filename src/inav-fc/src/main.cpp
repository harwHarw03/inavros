#include <main.hpp>

int main(int argc, char* argv[]) {
    const std::string device =
        (argc > 1) ? std::string(argv[1]) : "/dev/ttyUSB0";
    const size_t baudrate = (argc > 2) ? std::stoul(argv[2]) : 115200;

    SubCallbacks subs;

    msp::client::Client client;
    client.start(device, baudrate);

    // using lambda callback with stored function object
    const std::function<void(const msp::msg::RawImu&)> imu_cb2 =
        [](const msp::msg::RawImu& imu) {
            std::cout << imu;
            std::cout << msp::msg::ImuSI(
                imu, 512.0, 1.0 / 4.096, 0.92f / 10.0f, 9.80665f);
        };
    client.subscribe(imu_cb2, 0.1);

    client.subscribe(&SubCallbacks::onIdent, &subs, 10);
    client.subscribe(&SubCallbacks::onStatus, &subs, 1);
    client.subscribe(&SubCallbacks::onServo, &subs, 0.1);
    client.subscribe(&SubCallbacks::onMotor, &subs, 0.1);
    client.subscribe(&SubCallbacks::onRc, &subs, 0.1);
    client.subscribe(&SubCallbacks::onAttitude, &subs, 0.1);
    client.subscribe(&SubCallbacks::onAltitude, &subs, 0.1);
    client.subscribe(&SubCallbacks::onAnalog, &subs, 10);
    client.subscribe(&SubCallbacks::onRcTuning, &subs, 20);
    client.subscribe(&SubCallbacks::onPID, &subs, 20);
    client.subscribe(&SubCallbacks::onBox, &subs, 1);
    client.subscribe(&SubCallbacks::onMisc, &subs, 1);
    client.subscribe(&SubCallbacks::onMotorPins, &subs, 20);
    client.subscribe(&SubCallbacks::onBoxNames, &subs, 20);
    client.subscribe(&SubCallbacks::onPidNames, &subs, 20);
    client.subscribe(&SubCallbacks::onBoxIds, &subs, 20);
    client.subscribe(&SubCallbacks::onServoConf, &subs, 20);
    client.subscribe(&SubCallbacks::onDebugMessage, &subs, 1);
    client.subscribe(&SubCallbacks::onDebug, &subs, 1);

    // Ctrl+C to quit
    std::cin.get();

    client.stop();

    std::cout << "DONE" << std::endl;
}