class ChainedExceptionEx {
    public static void main(String[] args) {
        try {
            install();
        } catch (InstallException e) {
            System.out.println("InstallException 처리!");
            e.printStackTrace();
        } catch (Exception e) {
            System.out.println("Exception 처리!");
            e.printStackTrace();
        }
        System.out.println("main 종료");
    }
    static void install() throws InstallException {
        try {
            startInstall();
            copyFiles();
        } catch (SpaceException e) {
            InstallException ie = new InstallException("설치 중 예외발생");
            ie.initCause(e);
            throw ie;
        } catch (RuntimeException e) {
            InstallException ie = new InstallException("설치 중 예외발생");
            ie.initCause(e);
            throw ie;
        } finally {
            deleteTempFiles();
        }
    }

    static void startInstall() throws SpaceException {
        if(!enoughSpace()) {
            throw new SpaceException("설치할 공간이 부족합니다.");
        }
        if(!enoughMemory()) {
            // throw new MemoryException("메모리가 부족합니다.");
            throw new RuntimeException(new MemoryException("메모리가 부족합니다."));
        }
    }
    static void copyFiles() {
        System.out.println("copyFiles");
    }
    static void deleteTempFiles() {
        System.out.println("deleteTempFiles");
    }
    static boolean enoughSpace() {
        return true;
    }
    static boolean enoughMemory() {
        return false;
    }
}

class InstallException extends Exception {
    InstallException(String msg) {
        super(msg);
    }
}

class SpaceException extends Exception {
    SpaceException(String msg) {
        super(msg);
    }
}

class MemoryException extends Exception {
    MemoryException(String msg) {
        super(msg);
    }
}