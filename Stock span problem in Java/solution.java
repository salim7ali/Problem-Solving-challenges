import java.util.Stack;

public class solution {

    public static void displayArray(Integer[] result) {
        for(Integer ele: result){
            System.out.print(ele + " ");
        }
    }
    
    public static Integer[] stockSpanProblem(Integer[] stocks) {
        Stack<Integer> stockStack = new Stack<Integer>();
        Stack<Integer> indexStack = new Stack<Integer>();
        Stack<Integer> spanStack = new Stack<Integer>();
    
        Integer[] result = new Integer[stocks.length];
        
        
        stockStack.push(stocks[0]);
        indexStack.push(0);
        spanStack.push(1);
        
        Integer currSpan = 1;
        Integer i = 1;
        while(spanStack.empty() == false && i!=stocks.length){
            if(stocks[i] < stockStack.peek()){
                stockStack.push(stocks[i]);
                indexStack.push(i);
                spanStack.push(1);
                i += 1;
                continue;
            }
            while(stocks[i] > stockStack.peek()){
                currSpan += spanStack.peek();
                result[indexStack.peek()] = spanStack.peek();
                
                spanStack.pop();
                indexStack.pop();
                stockStack.pop();
            }
            
            stockStack.push(stocks[i]);
            indexStack.push(i);
            spanStack.push(currSpan);
            currSpan =1;
            i+=1;
        }
        while(spanStack.empty() == false){
            result[indexStack.peek()] = spanStack.peek();
            
            spanStack.pop();
            indexStack.pop();
            stockStack.pop();

        }


        return result;
    }
    public static void main(String[] args) {
        Integer[] stocks = {100, 80,60, 60, 70, 60, 75, 85};
        Integer[] res = stockSpanProblem(stocks);

        displayArray(res);
    }
}
