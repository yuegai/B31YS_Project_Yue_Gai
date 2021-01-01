/*
* Introduction: Subscribe to /objects topic to get the position of sign relative to the robot 
*               and obtain the pose of the sign on the map by subscribing the robot's transform.
*               Then calculate the coordinate of the sign and display markers on the map.
* Reference: https://husarion.com/tutorials/ros-tutorials/4-visual-object-recognition/#recognizing-objects
*            https://wiki.ros.org/rviz/Tutorials/Markers:%20Basic%20Shapes
*            https://wiki.ros.org/tf/Tutorials/Writing%20a%20tf%20listener%20(C++)
*/

#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>
#include <opencv2/opencv.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>

ros::Publisher marker_pub;  
std::string marker_string;  

int id = 0;  
float x_pos_object; 
float y_pos_object;
float x_pos_robot; 
float y_pos_robot;

// Get the position of sign relative to the robot
void objectCallback(const std_msgs::Float32MultiArrayPtr &object)
{
   if (object->data.size() > 0)
   {
      // Read id of recognized object
      id = object->data[0];

      float objectWidth = object->data[1];
      float objectHeight = object->data[2];
      
      // Find corners OpenCV
      cv::Mat cvHomography(3, 3, CV_32F);
      std::vector<cv::Point2f> inPts, outPts;
 
      // Extract coefficients homography matrix
      cvHomography.at<float>(0, 0) = object->data[3];
      cvHomography.at<float>(1, 0) = object->data[4];
      cvHomography.at<float>(2, 0) = object->data[5];
      cvHomography.at<float>(0, 1) = object->data[6];
      cvHomography.at<float>(1, 1) = object->data[7];
      cvHomography.at<float>(2, 1) = object->data[8];
      cvHomography.at<float>(0, 2) = object->data[9];
      cvHomography.at<float>(1, 2) = object->data[10];
      cvHomography.at<float>(2, 2) = object->data[11];

      // Define corners of input plane
      inPts.push_back(cv::Point2f(0, 0));
      inPts.push_back(cv::Point2f(objectWidth, 0));
      inPts.push_back(cv::Point2f(0, objectHeight));
      inPts.push_back(cv::Point2f(objectWidth, objectHeight));
      cv::perspectiveTransform(inPts, outPts, cvHomography);

      // Calculate centre of object from its corners
      x_pos_object = (int)(outPts.at(0).x + outPts.at(1).x + outPts.at(2).x +outPts.at(3).x) /4;
	  y_pos_object = (int)(outPts.at(0).y + outPts.at(1).y + outPts.at(2).y +outPts.at(3).y) /4;
    }
}

// Obtain the pose of the robot
void poseCallback(const std_msg::String& msg) 
{   
    // Create tf broadcast object
    static tf2_ros::TransformBroadcaster br;
    // Store the coordinate transformation message to be published
    geometry_msgs::TransformStamped transformStamped;

    // Transform timestamp and frame ID
    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = "map";
    // Current coordinate system name to be published
    transformStamped.child_frame_id = marker_string;

    // Transform translation and rotation
    transformStamped.transform.translation.x = msg->x;
    transformStamped.transform.translation.y = msg->y;
    transformStamped.transform.translation.z = 0.0;
    transformStamped.transform.rotation.x = q.x();
    transformStamped.transform.rotation.y = q.y();
    transformStamped.transform.rotation.z = q.z();
    transformStamped.transform.rotation.w = q.w();

    tf2::Quaternion q;

    q.setRPY(0, 0, msg->theta);

    // Get the pose of robot
    x_pos_robot = (int)(transformStamped.transform.rotation.x)
    y_pos_robot = (int)(transformStamped.transform.rotation.y)
}

 int main(int argc, char **argv)
{
   std_msgs::String s;
   std::string str;
   str.clear();
   str.append("");
   std::to_string(3);
   s.data = str;
   ros::init(argc, argv, "basic_shapes");
   ros::init(argc,argv,"tf_transformpub");
   ros::NodeHandle n("~");
   ros::Subscriber sub = n.subscribe("/objects", 1, objectCallback); // Subscribe to /objects topic
   ros::Subscriber sub = n.subscribe("/base_link", 1, poseCallback); // Subscribe to /base_link topic
   ros::Rate loop_rate(1);
   marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1); // Prepare publisher for marker
   
   // display markers on the map
   while (ros::ok())
   {
      visualization_msgs::Marker marker;

      // Set the frame ID and timestamp
      marker.header.frame_id = "/map";
      marker.header.stamp = ros::Time::now();

      // Set the namespace and id for this marker
      marker.ns = "basic_shapes";
      marker.id = 0;

      // Set the marker type
      marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;

      // Set the marker action
      marker.action = visualization_msgs::Marker::ADD;

      // Set the pose of the marker 
      marker.pose.position.x = x_pos_object - x_pos_robot;
      marker.pose.position.y = y_pos_object - y_pos_robot;
      marker.pose.position.z = 0.0;
      marker.pose.orientation.x = 0.0;
      marker.pose.orientation.y = 0.0;
      marker.pose.orientation.z = 0.0;
      marker.pose.orientation.w = 1.0;

      // Set the scale of the marker
      marker.scale.z = 0.6;

      // Set the color of the marker
      marker.color.r = 1.0f;
      marker.color.g = 0.0f;
      marker.color.b = 0.0f;
      marker.color.a = 1.0;

      // Display the name of signs
      if (id==1)
      {
        marker.text="Alive Worker";
      }
      else if (id==2)
      {
        marker.text="Biohazard";
      }    
      else if (id==3)
      {
        marker.text="Danger";
      }  
      else if (id==4)
      {
        marker.text="Dead Worker";
      }        
      else if (id==5)
      {
        marker.text="No Smoking";
      }    
      else if (id==6)
      {
        marker.text="Radioactive";
      }  
      else if (id==7)
      {
        marker.text="Risk of Fire";
      }  
      else if (id==8)
      {
        marker.text="Toxic";
      }                    

      // Never to auto-delete
      marker.lifetime = ros::Duration();

      while (marker_pub.getNumSubscribers() < 1)
      {
        if (!ros::ok())
        {
          return 0;
        }
        sleep(1);
      }
    
      // Publish the marker
	  marker_pub.publish(marker);
  
      r.sleep();
    }
    
}
