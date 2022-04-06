#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase
{
  public:
    IntakeSubsystem();

    void setSpeed(double speed);

  private:
    // motor declarations go here
};
