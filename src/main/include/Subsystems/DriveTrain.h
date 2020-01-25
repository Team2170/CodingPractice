// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#pragma once

#include "frc/commands/Subsystem.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/Compressor.h"
#include "frc/WPILib.h
#include "rev/CANSparkMax.h"
#include "hal/HAL.h"
#include "frc/PowerDistributionPanel.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
std::shared_ptr<frc::Compressor> compressor;
std::shared_ptr<frc::PowerDistributionPanel> powerDistributionPanel;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static const int leftLeadDeviceID = 4, rightLeadDeviceID = 1, leftFollowDeviceID = 3, rightFollowDeviceID = 2;
	std::shared_ptr<frc::DifferentialDrive> differentialDrive;
	std::shared_ptr<rev::CANSparkMax> sparkMaxLeftLead;
	std::shared_ptr<rev::CANSparkMax> sparkMaxLeftFollow;
	std::shared_ptr<rev::CANSparkMax> sparkMaxRightLead;
	std::shared_ptr<rev::CANSparkMax> sparkMaxRightFollow;
	std::shared_ptr<frc::ADXRS450_Gyro> analogGyro;
	std::shared_ptr<rev::CANPIDController> pidControllerL;
	std::shared_ptr<rev::CANPIDController> pidControllerR;
	std::shared_ptr<rev::CANEncoder> encoderControllerL;
	std::shared_ptr<rev::CANEncoder> encoderControllerR;
	std::shared_ptr<frc::Relay> spikeLED;

	const double kGearRatio = 5.95;
	const double kWheelDiameter;
	const double ft = 0.305;
	const double d = (25.75/12); 			// [ft] distance between wheel centerlines is 26 in*** double check this on robot

	// PID Gains for closed-loop velocity control
	const double kP, kI = 0, kD = 0, kIz = 0, kFF, kMaxOutput = 1, kMinOutput = -1;
	
	// Max RPM for motors
	const double maxRPM = 5600;
	const double maxFeetPerSec;
	const double maxAccelPerSec;

	// Gains for closed-loop velocity control FOR VISION 
	double kP_Vision = 2;
	double kP_Omega = 0.075;
	double omega_Max = 2*M_PI;
	double kP_Align_Master;
public:
DriveTrain();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void TankDrive(double left, double right);
	void ArcadeDrive(double xSpeed, double zRotation);
	void StopMotors(void);
	void VelocityArcade(double xSpeed, double zRotation, bool squaredInputs = true);
	void VelocityTankDrive(double left, double right, bool squaredInputs = true);
	void ClosedLoopVelocityControl(double speed);
	void TankDriveVelocityError(double velocity, double error);
	void SmartMotionDrive(double distance);
	void SmartMotionVelocity(double vFPS);
	double GetPosition() { return encoderControllerL->GetPosition();}
	double GetVelocity();
	void SetLEDOn(bool LEDOn);
	void ZeroPosition();
	void VisionSteerController(double angle, double error, double distance);		// returns [v, omega]

	// Gyro methods
	void ResetGyro()  { analogGyro->Reset();}
	double GetGyroAngle() {return analogGyro->GetAngle();}

	double FPStoRPM(double fps);
	double RPMtoFPS(double rpm);

	void SetMaxVelocity(double fps) {
		pidControllerL->SetSmartMotionMaxVelocity(fps);
    	pidControllerR->SetSmartMotionMaxVelocity(fps);
	}
	void SetMaxVelocity() {
		pidControllerL->SetSmartMotionMaxVelocity(maxFeetPerSec);
    	pidControllerR->SetSmartMotionMaxVelocity(maxFeetPerSec);
	}

	void SetMaxAccel(double accel) {
		pidControllerL->SetSmartMotionMaxAccel(accel);
    	pidControllerR->SetSmartMotionMaxAccel(accel);
	}
	void SetMaxAccel() {
		pidControllerL->SetSmartMotionMaxAccel(maxAccelPerSec);
    	pidControllerR->SetSmartMotionMaxAccel(maxAccelPerSec);
	}

	double GetMaxVelocity() { return pidControllerL->GetSmartMotionMaxVelocity();}
};

