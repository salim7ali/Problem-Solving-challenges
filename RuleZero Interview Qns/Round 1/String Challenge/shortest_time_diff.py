from datetime import datetime, timedelta 

def shortest_time_diff(time_list):
    BEGIN_TIME = "12:00am"
    BEGIN_TIME = datetime.strptime(BEGIN_TIME, "%I:%M%p") 

    minutes_list = []
    for time in time_list:
        time = datetime.strptime(time, "%I:%M%p")
        time_in_minutes = int((time-BEGIN_TIME)/timedelta(minutes=1))
        minutes_list.append(time_in_minutes)
    minutes_list.sort()
    
    smallest_diff = 999999
    for i in range(1, len(minutes_list)):
        if (minutes_list[i]-minutes_list[i-1]) < smallest_diff:
            smallest_diff =  minutes_list[i]-minutes_list[i-1]
    
    return smallest_diff


if __name__ == '__main__':
    print(shortest_time_diff(["2:10pm", "1:30pm", "10:30am", "4:42pm"]))
    print(shortest_time_diff(["1:10pm", "4:40am", "5:00pm"]))
    print(shortest_time_diff(["10:00am", "11:45pm", "5:00am", "12:01am"]))