//Student Name: Nathan Wandera
//LSU ID: 891973040

package CakeShop;


public class Cake implements Comparable<Cake> {
    
    private String flavor;
    private int tiers;
    private double price;

    public Cake()
    {}

    public Cake(String flavor, int tiers, double price)
    {
        this.flavor = flavor;
        this.tiers = tiers;
        this.price = price;
    }

    public int compareTo(Cake other)
    {
        return flavor.compareTo(other.flavor);
    }

    public void setPrice(double price)
    {
        this.price = price;
    }

    public void printCard()
    {   
        System.out.printf("A %d tier %s cake        $%.2f\n", tiers, flavor,price);
    }

    public static void main(String[] args)
    {

        Inventory cakeInventory = new Inventory();

        cakeInventory.addCake(new Cake("Chocolate", 1, 149.99));
        cakeInventory.addCake(new Cake("Chocolate", 3, 299.99));
        cakeInventory.addCake(new Cake("Carrot", 2, 99.99));
        cakeInventory.addCake(new Cake("Vanilla", 6, 199.99));

        cakeInventory.listInventory();
    }
}
