#pragma once

namespace DriveConstants
{
// can IDs
constexpr int kLeftMotorFront = 12;
constexpr int kLeftMotorFollower = 13;
constexpr int kRightMotorFront = 14;
constexpr int kRightMotorFollower = 15;

// motor inversions
constexpr bool kLeftMotorInvert = false;
constexpr bool kRightMotorInvert = true;

// encoder convertion factor
constexpr double kEncoderUnitsPerRevolution = 2048.0;
constexpr double kWheelDiameterInches = 4.0;
constexpr double kWheelCircumferenceInches = kWheelDiameterInches * M_PI;
constexpr double kGearRatio = 10.75 / 1.0;
constexpr double kEncoderUnitsPerInch = kEncoderUnitsPerRevolution * kGearRatio / kWheelCircumferenceInches;
} // namespace DriveConstants

namespace ClimberConstants
{
// can IDs
constexpr int kRightMotor = 10;
constexpr int kLeftMotor = 11;

// motor configurations
constexpr bool kInverted = false;

// climb configuration
constexpr double kManualClimberSpeed = 0.5;
constexpr double kClimberSpeed = 0.5;
constexpr double kClimberDistanceInches = 10.0;

// encoder convertion factor
constexpr double kEncoderUnitsPerRevolution = 48.0;
constexpr double kPulleyDiameter = 2.0;
constexpr double kPulleyCircumference = kPulleyDiameter * M_PI;
constexpr double kGearRatio = 20.0;
constexpr double kEncoderUnitsPerInch = kEncoderUnitsPerRevolution / (kGearRatio * kPulleyCircumference);
} // namespace ClimberConstants

namespace AutoConstants
{
constexpr double kAutoDriveSpeed = .5;
constexpr double kAutoDriveDistanceInches = 60;
} // namespace AutoConstants

namespace OIConstants
{
constexpr int driverControllerPort = 0;
constexpr int operatorControllerPort = 1;
constexpr int driverControllerLeftClimberUpButton = 3;
constexpr int driverControllerLeftClimberDownButton = 5;
constexpr int driverControllerRightClimberUpButton = 4;
constexpr int driverControllerRightClimberDownButton = 6;
constexpr int driverControllerClimberDownButton = 11;
constexpr int driverControllerClimberUpButton = 12;
} // namespace OIConstants