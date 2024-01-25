package org.example.FIFO;

public class FQueue<T> {
    //

    private static class FifoItem<T> {
        private T mItem;
        private FifoItem<T> mNext = null;

        public FifoItem(T item) {
            mItem = item;
        }

        public void setNext(FifoItem<T> mNext) {
            this.mNext = mNext;
        }

        public void setItem(T item) {
            mItem = item;
        }

        public FifoItem<T> getNext() {
            return mNext;
        }

        public T getItem() {
            return mItem;
        }
    }

    //
    // Wlasciwosci klasy FQueue


    FifoItem<T> mHead = null;
    FifoItem<T> mTail = null;

    //
    // Prywatne metody pomocnicze

    private FifoItem<T> getHead() {
        return mHead;
    }

    private void setHead(FifoItem<T> mHead) {
        this.mHead = mHead;
    }

    private FifoItem<T> getTail() {
        return mTail;
    }

    private void setTail(FifoItem<T> mTail) {
        this.mTail = mTail;
    }

    // Metoda ktora kasuje pierwszy do odczytu element z kolejki ( tylko 1 element )
    private void FQDel() throws FifoException {
        try {
            // Jesli kolejka jest pusta to nie ma co usuwac
            if (this.getHead() == null) {
                throw new FifoException(FifoExceptionCode.IS_EMPTY_ERROR);
            }

            // Zapamietujemy wskaznik na glowe kolejki
            FifoItem<T> pTemp = this.getHead();

            // Ustawiamy glowe kolejki na nastepny element
            this.setHead(this.getHead().getNext());

            // Sprawdzamy czy kolejka jest pusta i jesli tak to ustawiamy ogon na nullptr
            if (this.FQEmpty()) this.setTail(null);

        } catch (FifoException e) {
            e.printMessage();
        }

    }

    //
    // Publiczne metody
    public boolean FQEmpty() {
        return this.getHead() == null;
    }

    public int FQEnqueue(T item) throws FifoException {
        try {
            FifoItem<T> pNew = null;

            // Proba zaalokowania pamieci na nowy element
            try {
                pNew = new FifoItem<>(item);
            } catch (OutOfMemoryError e) {
                throw new FifoException(FifoExceptionCode.ALLOCATION_ERROR);
            }

            // Jesli kolejka jest pusta to ustawiamy glowe i ogon na nowy element
            if (this.FQEmpty()) {
                this.setHead(pNew);
            } else {
                // Ustawiamy wskaznik ogona na nowy element
                this.getTail().setNext(pNew);
            }

            // Ustawiamy wskaznik ogona na nowy element
            this.setTail(pNew);

            return 0;
        } catch (FifoException e) {
            e.printMessage();
            return -1;
        }
    }

    public T FQDequeue() throws FifoException {
        try {
            // Jesli kolejka jest pusta to nie ma co usuwac
            if (this.FQEmpty()) {
                throw new FifoException(FifoExceptionCode.IS_EMPTY_ERROR);
            }

            // Zapamietujemy wskaznik na glowe kolejki
            T result = this.getHead().getItem();

            this.FQDel();

            return result;
        } catch (FifoException e) {
            e.printMessage();
            return null;
        }
    }

    public void FQClear() throws FifoException {
        while (!this.FQEmpty()) {
            this.FQDel();
        }
    }

    // Autorska metoda do wyswietlania kolejki
    public void FQPrint() throws FifoException {
        if (this.FQEmpty()) {
            System.out.println("Kolejka jest pusta");
            return;
        }

        FifoItem<T> item = this.getHead();
        int i = 0;

        while (item != null) {
            System.out.println("Element " + i++ + ": " + item.getItem().toString());
            item = item.getNext();
        }
    }

    // Autorska metoda do wyswietlania kolejki
    public void FQPrint(boolean introductionMessage) throws FifoException {
        if (introductionMessage) System.out.println("Zawartosc kolejki: ");

        FQPrint();
    }

    public void FQPrint(String message) throws FifoException {
        System.out.println(message);

        FQPrint();
    }
}
