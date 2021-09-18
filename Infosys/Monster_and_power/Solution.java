import java.util.*;

class Monster{
    Integer power;
    Integer bonus;

    Monster(Integer pow, Integer bon){
        power = pow;
        bonus = bon;
    }
    
    @Override
    public String toString() {
        return ("{Power: "+power+" Bonus: "+bonus+"}");
    }
    
}

class MonsterComparator implements Comparator<Monster>{
    @Override
    public int compare(Monster o1, Monster o2) {
        if(o1.power > o2.power)
            return 1;
        else if(o1.power < o2.power)
            return -1;
        return 0;
    }
}

public class Solution {
    public static void main(String[] args) {
        // Integer myPower = 123;
        Integer myPower = 100;

        PriorityQueue<Monster> pq = new PriorityQueue<>(new MonsterComparator());
        // pq.offer(new Monster(78, 10));
        // pq.offer(new Monster(130, 0));
        pq.offer(new Monster(101, 100));
        pq.offer(new Monster(100, 1));
        pq.offer(new Monster(304, 524));

        Integer monstersDefeated = 0;
        while(true){
            if(pq.isEmpty() == false && pq.peek().power<=myPower){
                myPower += pq.peek().bonus;
                pq.poll();
                monstersDefeated += 1;
            }else
                break;

        }

        System.out.println(monstersDefeated);
    }
}
