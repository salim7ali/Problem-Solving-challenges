from datetime import datetime, timedelta 

def shortest_time_diff(time_list):

    minutes_list = []
    for time in time_list:
        time = datetime.strptime(time, "%I:%M%p")
        print(time)
        

if __name__ == '__main__':
    print(shortest_time_diff(["2:10pm", "1:30pm", "10:30am", "4:42pm"]))