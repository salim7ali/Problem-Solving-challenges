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
        // TODO Auto-generated method stub
        return super.toString();
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

        PriorityQueue<Monster> pq = new PriorityQueue<>(new MonsterComparator());
        pq.offer(new Monster(78, 10));
        pq.offer(new Monster(130, 0));
        pq.offer(new Monster(80, 0));

        System.out.println(pq.peek().bonus);
    }
}
