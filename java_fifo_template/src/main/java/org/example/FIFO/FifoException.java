package org.example.FIFO;

public class FifoException extends Throwable {
    private final FifoExceptionCode code;

    public FifoException(FifoExceptionCode code) {
        this.code = code;
    }

    public FifoExceptionCode getCode() {
        return code;
    }

    public String getMessage() {
        return switch (this.code) {
            case ALLOCATION_ERROR-> "ERROR: Nie udalo sie zaalokowac pamieci dla kolejki FIFO";
            case IS_EMPTY_ERROR -> "ERROR: Kolejka FIFO jest pusta";
            case OTHER_ERROR -> "ERROR: Nieznany blad";
        };
    }

    public void printMessage() {
        System.out.println(this.getMessage());
    }
}
