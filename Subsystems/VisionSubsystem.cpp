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
	try
	{
		if (camera.IsFreshImage())
		{
			ColorImage* img = camera.GetImage();
			BinaryImage *b_img_1 = img->ThresholdHSV(70, 85, 0, 255, 180, 240);
			delete img;
			BinaryImage *b_img_2 = b_img_1->RemoveSmallObjects(true, 0);
			delete b_img_1;
			BinaryImage *b_img_3 = b_img_2->ConvexHull(true);
			delete b_img_2;
			vector<ParticleAnalysisReport>* particles = b_img_3->GetOrderedParticleAnalysisReports();
			delete b_img_3;
			cout << particles->size() << endl;
			for (unsigned int i = 0; i < particles->size(); i++)
				std::cout << particles->at(i).center_mass_x << ", " << particles->at(i).center_mass_y  << ", " << (particles->at(i).boundingRect.width / particles->at(i).boundingRect.height) << std::endl;
		}
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}
}
