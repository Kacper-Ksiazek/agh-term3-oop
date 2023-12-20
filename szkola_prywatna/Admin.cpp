#include "Admin.h"

string Admin::getRole() const {
    switch (m_Role) {
        case MLODSZY_SPECJALISTA:
            return "mlodszy specjalista";
        case SPECJALISTA:
            return "specjalista";
        case STARSZY_SPECJALISTA:
            return "starszy specjalista";
    }
}
