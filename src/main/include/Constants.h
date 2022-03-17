#pragma once

namespace DriveConstants
{
    constexpr int kLeftMotorFront = 12;
    constexpr int kLeftMotorFollower = 13;
    constexpr int kRightMotorFront = 14;
    constexpr int kRightMotorFollower = 15;
}

namespace ClimberConstants
{
    constexpr int kRightMotor = 10;
    constexpr int kLeftMotor = 11;
    constexpr int kLeftEncoderFront = 0;
    constexpr int kLeftEncoderFollower = 1;
    constexpr int kRightEncoderFront = 2;
    constexpr int kRightEncoderFollower = 3;
    constexpr double kClimberSpeed = 0.5;
    constexpr bool kInverted = false;

    constexpr double kEncoderUnitsPerRevolution = 48.0;
    constexpr double kPulleyDiameter = 2.0;
    constexpr double kPulleyCircumference = kPulleyDiameter * M_PI;
    constexpr double kGearRatio = 20.0;
    constexpr double kEncoderUnitsPerInch = kEncoderUnitsPerRevolution / (kGearRatio * kPulleyCircumference);
}

namespace AutoConstants
{
    constexpr double kEncoderUnitsPerRevolution = 2048.0;
    constexpr double kWheelDiameterInches = 4.0;
    constexpr double kWheelCircumferenceInches = kWheelDiameterInches * M_PI;
    constexpr double kGearRatio = 10.75;
    constexpr double kEncoderUnitsPerInch = kEncoderUnitsPerRevolution * kGearRatio / kWheelCircumferenceInches;

    constexpr double kAutoDriveSpeed = .5;
    constexpr double kAutoDriveForwardDistanceInches = 60;
    constexpr double kAutoDriveForwardBackInches = 60;
}

namespace OIConstants
{
    constexpr int driverControllerPort = 0;
    constexpr int driverControllerLeftClimberUpButton = 3;
    constexpr int driverControllerLeftClimberDownButton = 5;
    constexpr int driverControllerRightClimberUpButton = 4;
    constexpr int driverControllerRightClimberDownButton = 6;
}