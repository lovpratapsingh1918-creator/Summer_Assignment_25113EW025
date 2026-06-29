#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_NAME 50

typedef struct {
    int productID;
    char productName[MAX_NAME];
    int quantity;
    float price;
    int minStock;
} Product;

Product inventory[MAX_PRODUCTS];
int totalProducts = 0;

// Function to display main menu
void displayMenu() {
    printf("\n");
    printf("=============================================\n");
    printf("     INVENTORY MANAGEMENT SYSTEM           \n");
    printf("=============================================\n");
    printf("1.  Add new product\n");
    printf("2.  View all inventory\n");
    printf("3.  Search product\n");
    printf("4.  Update stock\n");
    printf("5.  Update price\n");
    printf("6.  Delete product\n");
    printf("7.  Display inventory report\n");
    printf("8.  Low stock alert\n");
    printf("9.  Calculate total inventory value\n");
    printf("10. Exit\n");
    printf("=============================================\n");
}

// Function to check if product ID already exists
int isProductIDExists(int id) {
    for (int i = 0; i < totalProducts; i++) {
        if (inventory[i].productID == id) {
            return 1;
        }
    }
    return 0;
}

// Function to add a new product
void addProduct() {
    if (totalProducts >= MAX_PRODUCTS) {
        printf("\n*** Inventory is full! Cannot add more products. ***\n");
        return;
    }

    int id;
    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    if (isProductIDExists(id)) {
        printf("*** Product ID already exists! ***\n");
        return;
    }

    printf("Enter Product Name: ");
    scanf("%49s", inventory[totalProducts].productName);

    printf("Enter Quantity: ");
    scanf("%d", &inventory[totalProducts].quantity);

    printf("Enter Price per unit: ");
    scanf("%f", &inventory[totalProducts].price);

    printf("Enter Minimum Stock Level: ");
    scanf("%d", &inventory[totalProducts].minStock);

    inventory[totalProducts].productID = id;
    totalProducts++;

    printf("\n*** Product added successfully! ***\n");
}

// Function to view all inventory
void viewInventory() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    printf("\n");
    printf("=====================================================\n");
    printf("%-8s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Quantity", "Price", "Min Stock");
    printf("=====================================================\n");

    for (int i = 0; i < totalProducts; i++) {
        printf("%-8d %-20s %-10d %-10.2f %-10d\n",
               inventory[i].productID,
               inventory[i].productName,
               inventory[i].quantity,
               inventory[i].price,
               inventory[i].minStock);
    }

    printf("=====================================================\n");
    printf("Total Products: %d\n", totalProducts);
}

// Function to search for a product
void searchProduct() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    int searchID;
    printf("Enter Product ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < totalProducts; i++) {
        if (inventory[i].productID == searchID) {
            printf("\n");
            printf("========== Product Found ==========\n");
            printf("Product ID: %d\n", inventory[i].productID);
            printf("Product Name: %s\n", inventory[i].productName);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price per unit: %.2f\n", inventory[i].price);
            printf("Minimum Stock Level: %d\n", inventory[i].minStock);
            printf("Total Value: %.2f\n", inventory[i].quantity * inventory[i].price);
            printf("===================================\n");
            return;
        }
    }

    printf("\n*** Product not found! ***\n");
}

// Function to update stock quantity
void updateStock() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    int productID, newQuantity;
    printf("Enter Product ID: ");
    scanf("%d", &productID);

    for (int i = 0; i < totalProducts; i++) {
        if (inventory[i].productID == productID) {
            printf("Current Quantity: %d\n", inventory[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);

            if (newQuantity < 0) {
                printf("\n*** Quantity cannot be negative! ***\n");
                return;
            }

            inventory[i].quantity = newQuantity;
            printf("\n*** Stock updated successfully! ***\n");
            return;
        }
    }

    printf("\n*** Product not found! ***\n");
}

// Function to update price
void updatePrice() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    int productID;
    float newPrice;
    printf("Enter Product ID: ");
    scanf("%d", &productID);

    for (int i = 0; i < totalProducts; i++) {
        if (inventory[i].productID == productID) {
            printf("Current Price: %.2f\n", inventory[i].price);
            printf("Enter new price: ");
            scanf("%f", &newPrice);

            if (newPrice < 0) {
                printf("\n*** Price cannot be negative! ***\n");
                return;
            }

            inventory[i].price = newPrice;
            printf("\n*** Price updated successfully! ***\n");
            return;
        }
    }

    printf("\n*** Product not found! ***\n");
}

// Function to delete a product
void deleteProduct() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    int productID;
    printf("Enter Product ID to delete: ");
    scanf("%d", &productID);

    for (int i = 0; i < totalProducts; i++) {
        if (inventory[i].productID == productID) {
            // Shift remaining products
            for (int j = i; j < totalProducts - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            totalProducts--;
            printf("\n*** Product deleted successfully! ***\n");
            return;
        }
    }

    printf("\n*** Product not found! ***\n");
}

// Function to display inventory report
void displayReport() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    printf("\n");
    printf("============================================================\n");
    printf("                 INVENTORY REPORT                           \n");
    printf("============================================================\n");
    printf("%-8s %-20s %-8s %-10s %-12s\n", "ID", "Name", "Qty", "Price", "Total Value");
    printf("============================================================\n");

    float totalValue = 0;
    for (int i = 0; i < totalProducts; i++) {
        float productValue = inventory[i].quantity * inventory[i].price;
        totalValue += productValue;
        printf("%-8d %-20s %-8d %-10.2f %-12.2f\n",
               inventory[i].productID,
               inventory[i].productName,
               inventory[i].quantity,
               inventory[i].price,
               productValue);
    }

    printf("============================================================\n");
    printf("Total Inventory Value: Rs. %.2f\n", totalValue);
    printf("============================================================\n");
}

// Function to display low stock alert
void lowStockAlert() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    printf("\n");
    printf("========== LOW STOCK ALERT ==========\n");
    int lowStockCount = 0;

    for (int i = 0; i < totalProducts; i++) {
        if (inventory[i].quantity <= inventory[i].minStock) {
            printf("Product ID: %d\n", inventory[i].productID);
            printf("Product Name: %s\n", inventory[i].productName);
            printf("Current Stock: %d (Minimum: %d)\n", inventory[i].quantity, inventory[i].minStock);
            printf("-----------------------------------\n");
            lowStockCount++;
        }
    }

    if (lowStockCount == 0) {
        printf("No products with low stock!\n");
    }

    printf("=====================================\n");
}

// Function to calculate total inventory value
void calculateTotalValue() {
    if (totalProducts == 0) {
        printf("\n*** Inventory is empty! ***\n");
        return;
    }

    float totalValue = 0;
    int totalQuantity = 0;

    for (int i = 0; i < totalProducts; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
        totalQuantity += inventory[i].quantity;
    }

    printf("\n");
    printf("========== INVENTORY SUMMARY ==========\n");
    printf("Total Products: %d\n", totalProducts);
    printf("Total Quantity: %d\n", totalQuantity);
    printf("Total Inventory Value: Rs. %.2f\n", totalValue);
    printf("=======================================\n");
}

int main() {
    int choice;

    printf("\n");
    printf("=============================================\n");
    printf("  WELCOME TO INVENTORY MANAGEMENT SYSTEM   \n");
    printf("=============================================\n");

    while (1) {
        displayMenu();
        printf("\nEnter your choice (1-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                viewInventory();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateStock();
                break;

            case 5:
                updatePrice();
                break;

            case 6:
                deleteProduct();
                break;

            case 7:
                displayReport();
                break;

            case 8:
                lowStockAlert();
                break;

            case 9:
                calculateTotalValue();
                break;

            case 10:
                printf("\nThank you for using Inventory Management System. Goodbye!\n");
                printf("=============================================\n\n");
                return 0;

            default:
                printf("\n*** Invalid choice! Please enter a number between 1 and 10. ***\n");
        }
    }

    return 0;
}
