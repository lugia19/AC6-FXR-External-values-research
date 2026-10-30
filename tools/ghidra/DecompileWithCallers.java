// Decompiles the function containing an address, then every function that calls it (one level, or more with a
// depth argument). Usage (headless): -postScript DecompileWithCallers.java <address> [depth] [output file]
// @category AC6
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class DecompileWithCallers extends GhidraScript {
    private DecompInterface decompiler;
    private PrintWriter out;

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Address address = toAddr(args[0]);
        int depth = args.length > 1 ? Integer.parseInt(args[1]) : 1;
        out = args.length > 2 ? new PrintWriter(new FileWriter(args[2])) : new PrintWriter(System.out);
        decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);

        Set<Function> level = new LinkedHashSet<>();
        Function function = getFunctionContaining(address);
        if (function != null) {
            level.add(function);
        } else {  // Data (e.g. a string): start from the functions that reference it
            for (Reference ref : getReferencesTo(address)) {
                Function user = getFunctionContaining(ref.getFromAddress());
                out.println(address + " referenced from " + ref.getFromAddress() + " (" + ref.getReferenceType() + ") in "
                        + (user == null ? "<no function>" : user.getName() + " @ " + user.getEntryPoint()));
                if (user != null) {
                    level.add(user);
                }
            }
        }
        Set<Function> seen = new LinkedHashSet<>(level);
        for (int d = 0; d <= depth && !level.isEmpty(); d++) {
            Set<Function> next = new LinkedHashSet<>();
            for (Function f : level) {
                dump(f, d);
                for (Reference ref : getReferencesTo(f.getEntryPoint())) {
                    Function caller = getFunctionContaining(ref.getFromAddress());
                    out.println("  referenced from " + ref.getFromAddress() + " (" + ref.getReferenceType() + ") in "
                            + (caller == null ? "<no function>" : caller.getName() + " @ " + caller.getEntryPoint()));
                    if (caller != null && seen.add(caller)) {
                        next.add(caller);
                    }
                }
            }
            level = next;
        }
        out.close();
    }

    private void dump(Function f, int depth) {
        out.println("\n==== depth " + depth + ": " + f.getName() + " @ " + f.getEntryPoint() + " (" + f.getBody().getNumAddresses() + " bytes)");
        DecompileResults results = decompiler.decompileFunction(f, 120, monitor);
        out.println(results.decompileCompleted() ? results.getDecompiledFunction().getC() : "decompile failed: " + results.getErrorMessage());
    }
}
