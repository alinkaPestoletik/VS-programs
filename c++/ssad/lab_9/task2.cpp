#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class PayPal {
public:
    PayPal() = default;

    void makePayment(std::string item) {
        std::cout << "Making PayPal payment for item: " << item << std::endl;
    }

    bool verifyPayment(std::string transactionId) {
        std::cout << "Verifying PayPal payment with transaction ID: " << transactionId << std::endl;
        return true;
    }

    void refundPayment(std::string item) {
        std::cout << "Refunding PayPal payment for item: " << item << std::endl;
    }
};

class Stripe {
public:
    Stripe() = default;

    void chargePayment(std::string item) {
        std::cout << "Charging Stripe payment for item: " << item << std::endl;
    }

    bool verifyCharge(std::string transactionId) {
        std::cout << "Verifying Stripe payment with transaction ID: " << transactionId << std::endl;
        return true;
    }

    void issueRefund(std::string item) {
        std::cout << "Issuing Refund for Stripe payment for item: " << item << std::endl;
    }
};

class PaymentProvider {
public:
    virtual void proccessPayment(string item) = 0;

    virtual void handleRefund(string item) = 0;

    virtual void verifyPayment(string transactionID) = 0;
};


class PaypalAdapter : public PaymentProvider {
private:
    PayPal payPal;
public:
    PaypalAdapter(PayPal pal) : payPal(pal) {}

    void proccessPayment(string item) override {
        payPal.makePayment(item);
    }

    void handleRefund(string item) override {
        payPal.refundPayment(item);
    }

    void verifyPayment(string transactionID) {
        payPal.verifyPayment(transactionID);
    }
};


class StripeAdapter : public PaymentProvider {
private:
    Stripe stripe;
public:
    StripeAdapter(Stripe str) : stripe(str) {}

    void proccessPayment(string item) override {
        stripe.chargePayment(item);
    }

    void handleRefund(string item) override {
        stripe.issueRefund(item);
    }

    void verifyPayment(string transactionID) {
        stripe.verifyCharge(transactionID);
    }
};


class PaymentGateWay {
private:
    std::unordered_map<std::string, PaymentProvider *> paymentProviders;

public:
    PaymentGateWay() {
        paymentProviders = std::unordered_map<std::string, PaymentProvider *>();
    }

    void addPaymentProvider(std::string providerName, PaymentProvider *paymentProvider) {
        paymentProviders[providerName] = paymentProvider;
    }

    void processPayment(std::string providerName, std::string paymentInfo) {
        paymentProviders[providerName]->proccessPayment(paymentInfo);
    }

    void refundPayment(std::string providerName, std::string refundInfo) {
        paymentProviders[providerName]->handleRefund(refundInfo);
    }

    void verifyPayment(std::string providerName, std::string paymentInfo) {
        paymentProviders[providerName]->verifyPayment(paymentInfo);
    }
};


int main() {
    PaymentGateWay gateWay;
    PayPal *payPal = new PayPal();
    Stripe *stripe = new Stripe();
    PaypalAdapter *adoptedPal = new PaypalAdapter(*payPal);
    StripeAdapter *stripeAdopted = new StripeAdapter(*stripe);
    gateWay.addPaymentProvider("PayPal", adoptedPal);
    gateWay.addPaymentProvider("Stripe", stripeAdopted);

    gateWay.processPayment("PayPal", "apple");
    gateWay.processPayment("Stripe", "orange");

    gateWay.refundPayment("PayPal", "apple");
    gateWay.refundPayment("Stripe", "orange");

    gateWay.verifyPayment("PayPal", "1");
    gateWay.verifyPayment("Stripe", "2");
}
