#pragma once


namespace DriveConstants {
    constexpr int LeftMotorFront = 12;
    constexpr int LeftMotorFollower = 13;
    constexpr int RightMotorFront = 14;
    constexpr int RightMotorFollower = 15;
}

namespace AutoConstants {
    constexpr double kEncoderUnitsPerRevolution = 2048.0;
    constexpr double kWheelDiameterInches = 4.0;
    constexpr double kWheelCircumferenceInches = kWheelDiameterInches * M_PI;
    constexpr double kGearRatio = 10.75;
    constexpr double kEncoderUnitsPerInch = kEncoderUnitsPerRevolution * kGearRatio / kWheelCircumferenceInches;

    constexpr double kAutoDriveSpeed = .5;
    constexpr double kAutoDriveForwardDistanceInches = 60;
    constexpr double kAutoDriveForwardBackInches = 60;
}

namespace OIConstants {
    constexpr int driverControllerPort = 0;
}