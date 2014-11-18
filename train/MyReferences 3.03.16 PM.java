import java.util.*;
import java.lang.ref.*;

class VeryBig{
	private static final int SIZE = 10000;
	private long[] la = new long[SIZE];
	private String ident;
	public VeryBig(String id){ident = id;}
	public String toString(){return ident;}
	protected void finalize(){
		System.out.println("Finalize " + ident);
	}
}

public class MyReferences{
	private static ReferenceQueue<VeryBig> rq = new ReferenceQueue<VeryBig>();
	public static void checkout(){
		Reference<? extends VeryBig> inq = rq.poll();
		if (inq != null) {
			System.out.println("In queue: " + inq.get());
		}
	}
	public static void main(String[] args) {
		int size = 10;
		if (args.length > 0) {
			size = new Integer(args[0]);
		}
		LinkedList<SoftReference<VeryBig> > sa = new LinkedList<SoftReference<VeryBig> >();
		for (int i = 0; i < size; ++i) {
			sa.add(new SoftReference<VeryBig>(new VeryBig("Soft " + i), rq));
			System.out.println("Just created: " + sa.getLast());
			checkout();
		}
		LinkedList<WeakReference<VeryBig> > wa = new LinkedList<WeakReference<VeryBig> >();
		for (int i = 0; i < size; ++i) {
			wa.add(new WeakReference<VeryBig>(new VeryBig("Weak " + i), rq));
			System.out.println("Just created: " + wa.getLast());
			checkout();
		}
		SoftReference<VeryBig> s = new SoftReference<VeryBig>(new VeryBig("Soft"));
		WeakReference<VeryBig> w = new WeakReference<VeryBig>(new VeryBig("Weak"));
		System.gc();
		LinkedList<PhantomReference<VeryBig> > pa = new LinkedList<PhantomReference<VeryBig> >();
		for (int i = 0; i < size; ++i) {
			pa.add(new PhantomReference<VeryBig>(new VeryBig("Phantom " + i), rq));
			System.out.println("Just created: " + pa.getLast());
			checkout();
		}
	}
}