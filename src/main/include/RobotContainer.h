#pragma once

#include <frc/Joystick.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/ClimberSubsystem.h"

class RobotContainer
{
public:
  RobotContainer();
  frc2::Command *GetAutonomousCommand();

private:
  frc::Joystick m_driverController{OIConstants::driverControllerPort};

  DrivetrainSubsystem m_drive;
  ClimberSubsystem m_climber;

  frc2::InstantCommand m_LeftClimberUp{[this]
                                       { m_climber.setLeftSpeed(.5); },
                                       {&m_climber}};
  frc2::InstantCommand m_LeftClimberStop{[this]
                                         { m_climber.setLeftSpeed(0); },
                                         {&m_climber}};
  frc2::InstantCommand m_LeftClimberDown{[this]
                                         { m_climber.setLeftSpeed(-.5); },
                                         {&m_climber}};
  frc2::InstantCommand m_RightClimberUp{[this]
                                        { m_climber.setRightSpeed(.5); },
                                        {&m_climber}};
  frc2::InstantCommand m_RightClimberStop{[this]
                                          { m_climber.setRightSpeed(0); },
                                          {&m_climber}};
  frc2::InstantCommand m_RightClimberDown{[this]
                                          { m_climber.setRightSpeed(-.5); },
                                          {&m_climber}};
  
  frc2::SequentialCommandGroup m_Auto{
    frc2::FunctionalCommand(
      [this] { m_drive.ResetEncoders(); },
      [this] { m_drive.ArcadeDrive(AutoConstants::kAutoDriveSpeed, 0); },
      [this] (bool interrupted) { m_drive.ArcadeDrive(0, 0); },
      [this] { return m_drive.GetAverageEncoderDistanceInches() >= AutoConstants::kAutoDriveDistanceInches; },
      {&m_drive}
      ),
      frc2::FunctionalCommand(
      [this] { },
      [this] { m_drive.ArcadeDrive(-AutoConstants::kAutoDriveSpeed, 0); },
      [this] (bool interrupted) { m_drive.ArcadeDrive(0, 0); },
      [this] { return m_drive.GetAverageEncoderDistanceInches() <= 0; },
      {&m_drive}
      )
  };

  void ConfigureButtonBindings();
};
