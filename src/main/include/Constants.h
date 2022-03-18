#pragma once

#include <ctre/Phoenix.h>

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

// nuetral mode
constexpr NeutralMode kNeutralMode = NeutralMode::Coast;

// driving type
constexpr bool kSquareInputs = false;
} // namespace DriveConstants

namespace ClimberConstants
{
// can IDs
constexpr int kRightMotor = 10;
constexpr int kLeftMotor = 11;

// motor configurations
constexpr bool kInverted = false;

// climb configuration
constexpr double kManualClimberSpeed = 1;
constexpr double kClimberSpeed = 0.5;
constexpr double kClimberDistanceInches = 10.0;

// encoder convertion factor
constexpr double kEncoderUnitsPerRevolution = 42.0;
constexpr double kPulleyDiameter = .75;
constexpr double kPulleyCircumference = kPulleyDiameter * M_PI;
constexpr double kGearRatio = 20.0;
constexpr double kEncoderUnitsPerInch = kEncoderUnitsPerRevolution / (kGearRatio * kPulleyCircumference);
} // namespace ClimberConstants

namespace AutoConstants
{
constexpr double kAutoDriveSpeed = 0.75;
constexpr double kAutoDriveDistanceInches = 60;
} // namespace AutoConstants

namespace OIConstants
{
constexpr int driverControllerPort = 0;
constexpr int operatorControllerPort = 1;
constexpr int driverControllerChangeSquareInputs = 1;
constexpr int operatorControllerLeftClimberUpButton = 3;
constexpr int operatorControllerLeftClimberDownButton = 5;
constexpr int operatorControllerRightClimberUpButton = 4;
constexpr int operatorControllerRightClimberDownButton = 6;
constexpr int operatorControllerBothClimberDownButton = 11;
constexpr int operatorControllerBothClimberUpButton = 12;
constexpr int operatorControllerClimberDownButton = 13;
constexpr int operatorControllerClimberUpButton = 14;
} // namespace OIConstants