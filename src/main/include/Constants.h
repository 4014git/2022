#pragma once

#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>

namespace DriveConstants
{
// can IDs
constexpr int kLeftMotorFront = 10;
constexpr int kLeftMotorFollower = 11;
constexpr int kRightMotorFront = 12;
constexpr int kRightMotorFollower = 13;

// motor inversions
constexpr bool kLeftMotorInvert = false;
constexpr bool kRightMotorInvert = true;

// encoder convertion factor
constexpr double kEncoderUnitsPerRevolution = 2048.0;
constexpr double kWheelDiameterInches = 4.0;
constexpr double kGearRatio = 10.75;

constexpr double kWheelCircumferenceInches = kWheelDiameterInches * M_PI;
constexpr double kEncoderUnitsPerInch = kEncoderUnitsPerRevolution * kGearRatio / kWheelCircumferenceInches;

// neutral mode
constexpr NeutralMode kNeutralMode = NeutralMode::Coast;
} // namespace DriveConstants

namespace ClimberConstants
{
// can IDs
constexpr int kRightMotor = 20;
constexpr int kRightRotationMotor = 21;
constexpr int kLeftMotor = 22;
constexpr int kLeftRotationMotor = 23;

// motor configurations
constexpr bool kLeftInverted = true;
constexpr bool kLeftTransversalInverted = true;
constexpr bool kRightInverted = false;
constexpr bool kRightTransversalInverted = false;

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
constexpr int driverControllerSquareInputs = 1;

// operator controller buttons
constexpr int operatorControllerClimberLeftSide = 99;
constexpr int operatorControllerClimberRightSide = 99;

// constexpr int operatorControllerLeftClimberUpButton = 5;
// constexpr int operatorControllerLeftClimberDownButton = 3;

// constexpr int operatorControllerRightClimberUpButton = 6;
// constexpr int operatorControllerRightClimberDownButton = 4;

// constexpr int operatorControllerBothClimberDownButton = 11;
// constexpr int operatorControllerBothClimberUpButton = 12;

// constexpr int operatorControllerClimberByJoystickButton = 1;

// constexpr int operatorControllerLeftTransverseClimberUpButton = 99;
// constexpr int operatorControllerRightTransverseClimberUpButton = 99;

// constexpr int operatorControllerLeftTransverseClimberDownButton = 99;
// constexpr int operatorControllerRightTransverseClimberDownButton = 99;

// constexpr int operatorControllerBothTransverseClimberUpButton = 99;
// constexpr int operatorControllerBothTransverseClimberDownButton = 99;
} // namespace OIConstants