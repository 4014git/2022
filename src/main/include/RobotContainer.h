#pragma once

#include <frc/Joystick.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/ClimberSubsystem.h"
#include "subsystems/DrivetrainSubsystem.h"

class RobotContainer
{
  public:
    RobotContainer();
    frc2::Command *GetAutonomousCommand();

  private:
    frc::Joystick m_driverController{OIConstants::driverControllerPort};

    DrivetrainSubsystem m_drive;
    ClimberSubsystem m_climber;

    frc2::InstantCommand m_LeftClimberUp{[this] { m_climber.setLeftSpeed(ClimberConstants::kManualClimberSpeed); },
                                         {&m_climber}};
    frc2::InstantCommand m_LeftClimberStop{[this] { m_climber.setLeftSpeed(0); }, {&m_climber}};
    frc2::InstantCommand m_LeftClimberDown{[this] { m_climber.setLeftSpeed(-ClimberConstants::kManualClimberSpeed); },
                                           {&m_climber}};
    frc2::InstantCommand m_RightClimberUp{[this] { m_climber.setRightSpeed(ClimberConstants::kManualClimberSpeed); },
                                          {&m_climber}};
    frc2::InstantCommand m_RightClimberStop{[this] { m_climber.setRightSpeed(0); }, {&m_climber}};
    frc2::InstantCommand m_RightClimberDown{[this] { m_climber.setRightSpeed(-ClimberConstants::kManualClimberSpeed); },
                                            {&m_climber}};
    frc2::ParallelCommandGroup m_ClimberUp{
        frc2::FunctionalCommand(
            [this] { m_climber.ResetLeftEncoder(); },
            [this] { m_climber.setLeftSpeed(ClimberConstants::kClimberSpeed); },
            [this](bool interrupted) { m_climber.setLeftSpeed(0); },
            [this] { return m_climber.getLeftEncoderDistance() >= ClimberConstants::kClimberDistanceInches; }),
        frc2::FunctionalCommand(
            [this] { m_climber.ResetRightEncoder(); },
            [this] { m_climber.setRightSpeed(ClimberConstants::kClimberSpeed); },
            [this](bool interrupted) { m_climber.setRightSpeed(0); },
            [this] { return m_climber.getRightEncoderDistance() >= ClimberConstants::kClimberDistanceInches; })};

    frc2::ParallelCommandGroup m_ClimberDown{
        frc2::FunctionalCommand([this] {}, [this] { m_climber.setLeftSpeed(-ClimberConstants::kClimberSpeed); },
                                [this](bool interrupted) { m_climber.setLeftSpeed(0); },
                                [this] { return m_climber.getLeftEncoderDistance() <= 0; }),
        frc2::FunctionalCommand([this] {}, [this] { m_climber.setRightSpeed(-ClimberConstants::kClimberSpeed); },
                                [this](bool interrupted) { m_climber.setRightSpeed(0); },
                                [this] { return m_climber.getRightEncoderDistance() <= 0; })};

    frc2::SequentialCommandGroup m_Auto{
        frc2::FunctionalCommand(
            [this] { m_drive.ResetEncoders(); }, [this] { m_drive.ArcadeDrive(AutoConstants::kAutoDriveSpeed, 0); },
            [this](bool interrupted) { m_drive.ArcadeDrive(0, 0); },
            [this] { return m_drive.GetAverageEncoderDistanceInches() >= AutoConstants::kAutoDriveDistanceInches; },
            {&m_drive}),
        frc2::FunctionalCommand([this] {}, [this] { m_drive.ArcadeDrive(-AutoConstants::kAutoDriveSpeed, 0); },
                                [this](bool interrupted) { m_drive.ArcadeDrive(0, 0); },
                                [this] { return m_drive.GetAverageEncoderDistanceInches() <= 0; }, {&m_drive})};

    void ConfigureButtonBindings();
};
