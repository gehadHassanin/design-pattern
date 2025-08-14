# Observer Design Pattern

## Contents
- [What is the Observer Design Pattern?](#what-is-the-observer-design-pattern?)
- [Components of Observer Design Pattern](#Components-of-Observer-Design-Patterne)
- [When to use the Observer Design Pattern?](#When-to-use-the-Observer-Design-Pattern?)
- [When not to use the Observer Design Pattern?](#When-not-to-use-the-Observer-Design-Pattern?)

## What is the Observer Design Pattern?
The Observer Design Pattern is a behavioral design pattern that defines a **one-to-many** dependency between objects. When one object (the subject) changes state, all its dependents (observers) are notified and updated automatically.

## Components of Observer Design Pattern

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20240205164617/Observer-(1).webp)

### **Subject**:
- The subject maintains a list of observers.
- It Provides methods to register and unregister observers dynamically.
- Defines a method to notify observers of changes in its state.

### **Observer**:
- Defines an interface with an update method.

### **ConcreteSubject**:
- They hold the actual state or data that observers want to track. When this state changes, concrete subjects notify their observers.

### **ConcreteObserver**:
- Implements the observer interface. They register with a concrete subject and react when notified of a      state change.
- When the subject's state changes, the concrete observer's update() method is invoked, allowing it to take appropriate actions.


## When to use the Observer Design Pattern?
- When you need one object to notify multiple others about changes.
- When you want to keep objects loosely connected, so they don’t rely on each other’s details.
- When you want observers to automatically respond to changes in the subject’s state.
- When you want to easily add or remove observers without changing the main subject.
- When you’re dealing with event systems that require various components to react without direct connections.

## When not to use the Observer Design Pattern?
- When the relationships between objects are simple and don’t require notifications.
- When performance is a concern, as many observers can lead to overhead during updates.
- When the subject and observers are tightly coupled, as it defeats the purpose of decoupling.
- When number of observers is fixed and won’t change over time.
- When the order of notifications is crucial, as observers may be notified in an unpredictable sequence.