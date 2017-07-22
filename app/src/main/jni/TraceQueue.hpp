#pragma once

#include <opencv2/core.hpp>

#ifndef TRACE_QUEUE_H
#define TRACE_QUEUE_H


namespace mhealth{

class TraceQueue
{

private:
    const static int LENGTH = 30;
    
public:

    int Data[LENGTH][2];
    int front;
    int rear;
    int num;
    
    TraceQueue()
    {
        front = 0;
        rear = 0;
        num = 0;
    }


    bool empty()
    {
        return (front == rear);
    }

    void append(int _data[2])
    {
        Data[rear][0] = _data[0];
        Data[rear][1] = _data[1];
        rear++;
        num++;
        if(rear > LENGTH - 1)
            rear = 0;
        if(num > LENGTH)
        {
            front++;
            num = LENGTH;
        }        
        if(front > LENGTH - 1)
            front = 0;
    }

    void draw_trace(cv::Mat frame)
    {
        int index = front + 1;
        int p_index = front;
        if(num > 0)
        {
            for(int i = 1; i < num; i++)
            {
                if(index > LENGTH - 1)
                    index = 0;
                cv::Point p1 = cv::Point(Data[p_index][0], Data[p_index][1]);
                cv::Point p2 = cv::Point(Data[index][0], Data[index][1]);
                cv::line(frame, p1, p2, CV_RGB(255, 0, 0), 2);
                p_index = index;
                index ++;
            }
        }
    }
};  
  
}  
        
#endif //MHEALTH_TRACE_QUEUE_H
