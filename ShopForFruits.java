import java.util.Scanner;

public class ShopForFruits {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the price of strawberries: ");
        double priceOfStrawberries = Double.parseDouble(scan.nextLine());
        System.out.print("Enter the quantity of bananas: ");
        double quantityOfBananas = Double.parseDouble(scan.nextLine());
        System.out.print("Enter the quanity of oranges: ");
        double quantityOfOranges = Double.parseDouble(scan.nextLine());
        System.out.print("Enter the quantity of raspberries: ");
        double quantityOfRaspberries = Double.parseDouble(scan.nextLine());
        System.out.print("Enter the quantity of strawberries: ");
        double quantityOfStrawberries = Double.parseDouble(scan.nextLine());

        double priceOfRaspberries = priceOfStrawberries - 0.5 * priceOfStrawberries;
        double priceOfOranges = priceOfRaspberries - 0.4 * priceOfRaspberries;
        double priceOfBananas = priceOfRaspberries - 0.8 * priceOfRaspberries;

        double neededMoney = priceOfStrawberries * quantityOfStrawberries + priceOfRaspberries * quantityOfRaspberries +
                             priceOfBananas * quantityOfBananas + priceOfOranges * quantityOfOranges;

        System.out.printf("Needed money: %.2f",neededMoney);
    }
}
