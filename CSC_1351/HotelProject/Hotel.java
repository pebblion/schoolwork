package HotelProject;

public class Hotel {
    String name;
    int stars; 
    double rating, averageRoomPrice;

    Hotel(String name, int stars)
    {
        this.name = name;
        this.stars = stars;
    }

    public void setRating(double rating)
    {
        this.rating = rating;
    }

    public void setRoomPrice(double averageRoomPrice)
    {
        this.averageRoomPrice = averageRoomPrice;
    }

    public void printInfo()
    {
        System.out.println();
    }

}
