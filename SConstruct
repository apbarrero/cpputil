import subprocess
import os

env = DefaultEnvironment()
env['LINK'] = 'g++'

class cd:
    """Context manager for changing the current working directory"""
    def __init__(self, newPath):
        self.newPath = newPath

    def __enter__(self):
        self.savedPath = os.getcwd()
        os.chdir(self.newPath)

    def __exit__(self, etype, value, traceback):
        os.chdir(self.savedPath)

def build_cmake(target, source, env):
    build_path=os.path.dirname(target[0].abspath)
    if not os.path.exists(target[0].abspath):
        if not os.path.exists(build_path):
            os.mkdir(build_path)
        with cd(build_path):
            return subprocess.call("cmake " + os.path.join(source[0].abspath, os.pardir) + " && make", shell=True)

cmk = Builder(action = build_cmake)
env.Append(BUILDERS = {'cmake': cmk})

def runUnitTest(target, source, env):
    app = str(source[0].abspath)
    if not subprocess.call(app):
        open(str(target[0]),'w').write("PASSED\n")

env.cmake(os.path.join('gtest', 'build', 'libgtest.a'), os.path.join('gtest', 'tags', 'release-1.7.0', 'CMakeLists.txt'))
test_sources = ['cpputiltests.cc']
program = env.Program('test', test_sources, srcdir='tests', parse_flags='-I.', LIBS=['gtest_main', 'gtest', 'pthread'], LIBPATH=[os.path.join('gtest', 'build')])
Command('test.passed', 'test', runUnitTest)
