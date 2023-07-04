import shutil
from tqdm import tqdm
from dolfinx import io
from fenics import operators as fn


def solve(
    problem: fn.NonlinearProblem,
    time_line,
    change_func,
    save_func,
    DATA,
    domain,
    save=False,
    time_check=None,
):
    time_steps = tqdm(
        desc=f'Solving PDE. Time:{0:.3f}',
        iterable=time_line,
    )
    if not save:
        for step in time_steps:
            time_steps.set_description(f'Solving PDE. Time:{step:.2f}')
            problem.solve()
            change_func()
    else:
        sol_name = DATA.save_confs.dir + DATA.save_confs.solution_name
        try:
            shutil.rmtree(sol_name)
        except:
            pass
        save_path = sol_name + DATA.save_confs.file_name
        with io.XDMFFile(domain.comm, save_path + '.xdmf', 'w') as file:

            file.write_mesh(domain)

            for step in time_steps:
                if step in DATA.time.check:
                    time_steps.set_description(f'Solving PDE. Time:{step:.2f}')
                    save_func(file, step)

                problem.solve()
                change_func()
