#pragma once

#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>

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

// neutral mode
constexpr NeutralMode kNeutralMode = NeutralMode::Coast;

// default driving type
constexpr bool kDefualtSquareInputs = false;
} // namespace DriveConstants

namespace ClimberConstants
{
// can IDs
constexpr int kRightMotor = 10;
constexpr int kLeftMotor = 11;

// motor configurations
constexpr bool kLeftnverted = true;
constexpr bool kRightInverted = false;

// climb configuration
constexpr double kManualClimberSpeed = 1.0;

// neutral mode
constexpr rev::CANSparkMax::IdleMode kNeutralMode = rev::CANSparkMax::IdleMode::kBrake;
} // namespace ClimberConstants

namespace AutoConstants
{
constexpr double kAutoDriveSpeed = 0.6;
constexpr double kAutoDriveDistanceInches = 60;
} // namespace AutoConstants

namespace OIConstants
{
// controller ports
constexpr int driverControllerPort = 0;
constexpr int operatorControllerPort = 1;

// driver controller buttons
constexpr int driverControllerChangeSquareInputs = 1;

// operator controller buttons
constexpr int operatorControllerLeftClimberUpButton = 5;
constexpr int operatorControllerLeftClimberDownButton = 3;
constexpr int operatorControllerRightClimberUpButton = 6;
constexpr int operatorControllerRightClimberDownButton = 4;
constexpr int operatorControllerBothClimberDownButton = 11;
constexpr int operatorControllerBothClimberUpButton = 12;
constexpr int operatorControllerClimberByJoystickButton = 1;
} // namespace OIConstants