// Walks callers of each given function breadth-first (up to a depth) and prints the strings each visited function
// references, to identify which subsystem a function belongs to.
// Usage (headless): -postScript CallerStrings.java <output file> <depth> <address...>
// @category AC6
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;

public class CallerStrings extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter out = new PrintWriter(new FileWriter(args[0]));
        int depth = Integer.parseInt(args[1]);
        for (int i = 2; i < args.length; i++) {
            Function root = getFunctionContaining(toAddr(args[i]));
            out.println("##### " + args[i] + " " + (root == null ? "<none>" : root.getName()));
            if (root == null) {
                continue;
            }
            Set<Function> seen = new LinkedHashSet<>();
            Set<Function> level = new LinkedHashSet<>();
            level.add(root);
            seen.add(root);
            for (int d = 0; d <= depth && !level.isEmpty(); d++) {
                Set<Function> next = new LinkedHashSet<>();
                for (Function f : level) {
                    Set<String> strings = new TreeSet<>();
                    for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                        for (Reference r : ins.getReferencesFrom()) {
                            Data data = getDataAt(r.getToAddress());
                            if (data != null && data.hasStringValue()) {
                                strings.add(String.valueOf(data.getValue()));
                            }
                        }
                    }
                    out.println("  d" + d + " " + f.getName() + " @ " + f.getEntryPoint()
                            + (strings.isEmpty() ? "" : " :: " + String.join(" | ", strings)));
                    if (d == depth) {
                        continue;
                    }
                    for (Reference ref : getReferencesTo(f.getEntryPoint())) {
                        Function caller = getFunctionContaining(ref.getFromAddress());
                        if (caller != null && seen.add(caller) && seen.size() < 200) {
                            next.add(caller);
                        }
                    }
                }
                level = next;
            }
        }
        out.close();
    }
}
