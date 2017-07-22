#include "Spiral.h"


using namespace mhealth;


Spiral::Spiral()
{
}


Spiral::Spiral(int maxRadius)
{
	float radius_step = 10.0f;	
	float theta_step = CV_PI/10.0f;
	
	cv::Point2f target;
	
		float radius = 0.0f;
		float theta  = 0.0f;
		float x = 0.0f;
		float y = 0.0f;
		
		// Outward/Inward spiral: increase r
		int j = 1;		
		while (radius < maxRadius ){
		
		   // for one revolution
		   while (theta < j*2*CV_PI){
		   		
		   		// Update x and y
				x = radius * cos(theta);
				y = radius * sin(theta);
				
				// Save target point
				target = cv::Point2f(x,y);			
				trajectory.push_back(target);			
		
				// Increase theta
				theta  += theta_step;			
								
			}
			
			radius += radius_step;
			j++;
		}
		
		// Outward/Inward spiral: increase r
		j = 1;	
		theta = 0;  // reset angle
			
		while (radius > 0){
		
		   radius -= radius_step;
		
		   // for one revolution
		   while (theta < j*2*CV_PI){
		   		
		   		// Update x and y
				x = radius * cos(theta);
				y = radius * sin(theta);
				
				// Save target point
				target = cv::Point2f(x,y);			
				trajectory.push_back(target);			
		
				// Increase theta
				theta  += theta_step;			
								
			}		
			j++; 
		}
		
	 	trajectory.pop_back();
};


Spiral::~Spiral()
{
};
 
  
  
void Spiral::displayTargets(const cv::Mat &src, cv::Mat &dst, int counter)
{
	cv::Point2f center = cv::Point2f(src.cols/2, src.rows/2);
	
	int circ_counter = counter % trajectory.size();
	
	cv::Point2f traj_point;
	
	// Draw previous trajectory
    for (int i = 0; i < circ_counter; i++){
       	traj_point = cv::Point2f(center.x + trajectory[i].x, center.y + trajectory[i].y);
        cv:: circle(dst, traj_point, 8, cv::Scalar(0,255,0), 4);
    }
    
    // Draw current target
	traj_point = cv::Point2f(center.x + trajectory[circ_counter].x, center.y + trajectory[circ_counter].y);
    cv:: circle(dst, traj_point, 10, cv::Scalar(0,0,255), -1);
}


int Spiral::size(){
	return trajectory.size();
}
