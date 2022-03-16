#include "commands/DriveDistance.h"

DriveDistance::DriveDistance(DrivetrainSubsystem* subsystem, double distance, double speed)
  : m_drive(subsystem) {
  AddRequirements(subsystem);
  m_distance = distance;
  m_speed = speed;
}

// Called when the command is initially scheduled.
void DriveDistance::Initialize() {
  m_drive->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
  m_drive->ArcadeDrive(m_speed, 0);
}

// Called once the command ends or is interrupted.
void DriveDistance::End(bool interrupted) {
  m_drive->ArcadeDrive(0, 0);
}

// Returns true when the command should end.
bool DriveDistance::IsFinished() {
  return m_drive->GetAverageEncoderDistance() >= m_distance;
}
