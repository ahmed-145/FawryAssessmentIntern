# FawryAssessmentIntern

## 📝 The Task

### Fawry Rise Journey  
**Full Stack Development Internship Challenge**

Design an e-commerce system that has these features:

- Define products with name, price and quantity.
- Some products may expire (e.g. **Cheese** and **Biscuits**), others may not (e.g. **TV** and **Mobile**).
- Some products require shipping (e.g. **Cheese**, **TV**), while others do not (e.g. **Mobile scratch cards**).
  - Every shippable item should include its **weight**.
- Customers should be able to add a product to the cart with a specific quantity (not more than available stock).
- Customers should be able to checkout with items in the cart, and it should:
  - ✅ Print to console:
    - Order **subtotal** (sum of all item prices)
    - **Shipping fees**
    - **Total amount paid** (subtotal + shipping)
    - Customer's **current balance** after payment
  - ❌ Print errors if:
    - Cart is empty
    - Customer's balance is insufficient
    - A product is out of stock or expired
- All shippable items should be sent to a `ShippingService`, which accepts a list of objects implementing:
  - `string getName()`
  - `double getWeight()`

---

### 🧠 Notes

- You may use any language (Java recommended, C++ used here).
- Cover **corner cases** and document **assumptions**.
- **AI-generated** solutions are not allowed (this one is human-written).
- Provide code examples that show expected behavior.

---

### 🧪 Sample Code Usage

```cpp
cart.add(cheese, 2);
cart.add(tv, 3);
cart.add(scratchCard, 1);
checkout(customer, cart);

📦 Sample Console Output

** Shipment notice **
2x Cheese 400g
1x Biscuits 700g
Total package weight 1.1kg

** Checkout receipt **
2x Cheese 200
1x Biscuits 150
----------------------
Subtotal 350
Shipping 30
Amount 380

✅ End.


---

### 📌 How to Fix Yours:
1. Open your `README.md` in a code/text editor
2. Replace the content with the cleaned version above
3. Save the file
4. Then run:

```bash
git add README.md
git commit -m "Fix formatting in README"
git push
