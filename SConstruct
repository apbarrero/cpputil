env = DefaultEnvironment()
env['LINK'] = 'g++'

def runUnitTest(target, source, env):
    import subprocess
    app = str(source[0].abspath)
    if not subprocess.call(app):
        open(str(target[0]),'w').write("PASSED\n")

test_sources = ['cpputiltests.cc']
program = env.Program('test', test_sources, srcdir='tests', parse_flags='-I.', LIBS=['gtest_main', 'gtest', 'pthread'])
Command('test.passed', 'test', runUnitTest)
