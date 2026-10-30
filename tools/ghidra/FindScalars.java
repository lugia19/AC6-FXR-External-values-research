// Lists every instruction with a scalar operand equal to one of the given values, with its containing function.
// Usage (headless): -postScript FindScalars.java <output file> <value> [value...]
// @category AC6
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.scalar.Scalar;

public class FindScalars extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter out = new PrintWriter(new FileWriter(args[0]));
        Set<Long> values = new HashSet<>();
        for (int i = 1; i < args.length; i++) {
            values.add(Long.decode(args[i]));
        }
        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Instruction ins = it.next();
            for (int op = 0; op < ins.getNumOperands(); op++) {
                for (Object o : ins.getOpObjects(op)) {
                    if (o instanceof Scalar && values.contains(((Scalar) o).getValue())) {
                        Function f = getFunctionContaining(ins.getAddress());
                        out.println(((Scalar) o).getValue() + "\t" + ins.getAddress() + "\t" + ins + "\t"
                                + (f == null ? "<none>" : f.getName() + "@" + f.getEntryPoint()));
                    }
                }
            }
        }
        out.close();
    }
}
