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
constexpr int kLeftMotor = 20;
constexpr int kLeftRotationMotor = 21;
constexpr int kRightMotor = 22;
constexpr int kRightRotationMotor = 23;

// motor configurations
constexpr bool kLeftInverted = true;
constexpr bool kLeftTransversalInverted = true;
constexpr bool kRightInverted = false;
constexpr bool kRightTransversalInverted = false;

constexpr double kJoystickSpeedScale = 12.0/100.0;

// neutral mode
constexpr rev::CANSparkMax::IdleMode kNeutralMode = rev::CANSparkMax::IdleMode::kBrake;
} // namespace ClimberConstants

namespace IntakeConstants{
    constexpr int kLeftMotorRotation = 30;
    constexpr int kRightMotorRotation = 31;
    constexpr int kMotorIntake = 32;

    constexpr int kLeftMotorInvert = true;
    constexpr int kRightMotorInvert = false;
    constexpr int kMotorIntakeInvert = false;

    constexpr NeutralMode kRotationNeutralMode = NeutralMode::Brake;
    constexpr NeutralMode kIntakeNeutralMode = NeutralMode::Brake;
}

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
constexpr int operatorControllerClimberLeftSide = 6;
constexpr int operatorControllerClimberRightSide = 5;
constexpr int operatorControllerClimberFullSpeedForward = 1;
constexpr int operatorControllerClimberFullSpeedBackward = 2;
} // namespace OIConstants