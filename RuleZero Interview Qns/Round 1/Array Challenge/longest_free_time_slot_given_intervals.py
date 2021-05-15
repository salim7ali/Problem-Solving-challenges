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
        
        
    def ArrayChallenge():
        for time_slot in self.booked_slots:
            start_slot, end_slot = time_slot.split('-')

            start_slot = datetime.strptime(start_slot, "%I:%M%p") 
            start_min = start_slot.seconds/timedelta(minutes=1)
            
            end_slot = datetime.strptime(end_slot, "%I:%M%p") 
            end_min = end_slot.seconds/timedelta(minutes=1)

            inc_dec_1440 = []
            inc_dec_1440[start_min] += 1
            inc_dec_1440[end_min+1] -= 1

        for m in range(0, DAY_MINUTES):
            

            


if __name__ == "__main__":
    employee1 = Schedule(["10:00AM-12:30PM", "02:00AM-02:45PM", "09:10AM-09:50AM"])
    employee1.ArrayChallenge()