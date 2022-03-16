#pragma once

#include <frc/Joystick.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/FunctionalCommand.h>

#include "subsystems/DrivetrainSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  frc2::Command* GetAutonomousCommand();

 private:
  frc::Joystick m_driverController{OIConstants::driverControllerPort};

  DrivetrainSubsystem m_drive;

  frc2::FunctionalCommand m_Auto = frc2::FunctionalCommand(
      // Reset encoders on command start
      [this] { m_drive.ResetEncoders(); },
      // Drive forward while the command is executing
      [this] { m_drive.ArcadeDrive(AutoConstants::kAutoDriveSpeed, 0); },
      [this](bool interrupted) { m_drive.ArcadeDrive(0, 0); },
      // End the command when the robot's driven distance exceeds the desired
      // value
      [this] {
        return m_drive.GetAverageEncoderDistance() >= AutoConstants::kAutoDriveDistanceInches;
      },
      // Requires the drive subsystem
      {&m_drive});

  void ConfigureButtonBindings();
};
