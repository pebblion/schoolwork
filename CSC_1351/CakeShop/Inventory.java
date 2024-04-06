//Student Name:Nathan Wandera
//LSUID: 891973040

package CakeShop;

import java.util.ArrayList;
import java.util.Collections;

public class Inventory {

    private ArrayList<Cake> cakes = new ArrayList<>();

    public void addCake(Cake addCake)
    {
        cakes.add(addCake);
    }

    public void listInventory()
    {

        Collections.sort(cakes);

        for(int i = 0; i < cakes.size(); i++)
        {
            cakes.get(i).printCard();
        }
    }
}
