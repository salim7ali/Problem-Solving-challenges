# Have the function ArrayChallenge(strArr) read the strArr parameter being passed which will represent a full day 
# and will be filled with events that span from time X to time Y in the day. The format of each event will be hh:mmAM/PM-hh:mmAM/PM.
# For example, strArr may be ["10:00AM-12:30PM", "02:00AM-02:45PM", "09:10AM-09:50AM"]. Your program will have to output the longest
# amount of free time available between the start of your first event and the end of your last event in the format hh:mm. The
# start event should be the earliest event in the day and the latest event should be the latest event in the day. The __GCC_ASM_FLAG_OUTPUTS__for the 
from datetime import datetime, timedelta

class Schedule:
    DAY_MINUTES = (60*24)+1     # 1440
    
    def __init__(self, booked_slots):
        self.booked_slots = booked_slots
        
        # assuming BEGIN and END for the day to be at extremes 
        self.BEGIN_MINUTE = DAY_MINUTES-1
        self.END_MINUTE = 0

    def ArrayChallenge():
        for time_slot in self.booked_slots:
            start_slot, end_slot = time_slot.split('-')

            start_slot = datetime.strptime(start_slot, "%I:%M%p") 
            start_min = start_slot.seconds/timedelta(minutes=1)
            if start_min < self.BEGIN_MINUTE:
                self.BEGIN_MINUTE = start_min
            
            end_slot = datetime.strptime(end_slot, "%I:%M%p") 
            end_min = end_slot.seconds/timedelta(minutes=1)
            if self.END_MINUTE < end_min:
                self.END_MINUTE = end_min

            inc_dec_1440 = []
            inc_dec_1440[start_min] += 1
            inc_dec_1440[end_min+1] -= 1

        inc_dec_result_1440 = []
        curr_prefix_sum = 0
        for m in range(0, DAY_MINUTES):
            curr_prefix_sum += m
            inc_dec_result_1440[m] = curr_prefix_sum

            # if curr_prefix_sum==0:

        longest_free_time = 0
        curr_longest_free_time = 0
        for m in range(self.BEGIN_MINUTE+1, self.END_MINUTE):
            if inc_dec_result_1440[m] == 0:
                if inc_dec_result_1440[m-1] == 0:
                    curr_longest_free_time += 1
                else:
                    curr_longest_free_time = 1
                longest_free_time = max(longest_free_time, curr_longest_free_time)

        return longest_free_time
                    
                
            


if __name__ == "__main__":
    employee1 = Schedule(["10:00AM-12:30PM", "02:00AM-02:45PM", "09:10AM-09:50AM"])
    print(employee1.ArrayChallenge())