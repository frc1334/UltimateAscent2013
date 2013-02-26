#include "VisionSubsystem.h"
#include "nivision.h"
#include "../Robotmap.h"

VisionSubsystem::VisionSubsystem() : Subsystem("VisionSubsystem"),
	camera(AxisCamera::GetInstance("10.13.34.11"))
{
	//if (camera.GetWhiteBalance()    != AxisCameraParams::kWhiteBalance_Automatic) camera.WriteWhiteBalance(AxisCameraParams::kWhiteBalance_Automatic);
	//if (camera.GetResolution()      != AxisCameraParams::kResolution_320x240)     camera.WriteResolution(AxisCameraParams::kResolution_320x240);
	//if (camera.GetExposureControl() != AxisCameraParams::kExposure_Automatic)     camera.WriteExposureControl(AxisCameraParams::kExposure_Automatic);
}

void VisionSubsystem::InitDefaultCommand()
{
}

void VisionSubsystem::UpdateTracking()
{
	if (camera.IsFreshImage())
	{
		ColorImage* img = NULL;
		BinaryImage *b_img = NULL;
		camera.GetImage(img);
		// hue_high, hue_low, sat_high, sat_low, val_high, val_low
		b_img = img->ThresholdHSV(85, 70, 255, 0, 240, 180);
		b_img = b_img->RemoveSmallObjects(true, 0);
		b_img = b_img->ConvexHull(true);
		delete img;
		delete b_img;
		vector<ParticleAnalysisReport>* particles = b_img->GetOrderedParticleAnalysisReports();
		for (unsigned int i = 0; i < particles->size(); i++)
			std::cout << particles->at(i).center_mass_x << ", " << particles->at(i).center_mass_y  << ", " << (particles->at(i).boundingRect.width / particles->at(i).boundingRect.height) << std::endl;
	}
}
