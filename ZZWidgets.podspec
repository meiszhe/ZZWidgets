#
# Be sure to run `pod lib lint ZZWidgets.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZZWidgets'
  s.version          = '1.0.3.1'
  s.summary          = 'A short description of ZZWidgets.'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/meiszhe/ZZWidgets'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'meiszhe' => 'meiszhe1@163.com' }
  s.source           = { :git => 'https://github.com/meiszhe/ZZWidgets.git', :tag => s.version.to_s }

  s.ios.deployment_target = '14.0'

  s.subspec 'Core' do |core|
    core.frameworks = 'Foundation'
    core.vendored_frameworks = 'SDK/Core/ZZKitCore.xcframework'
  end

  s.subspec 'Voice' do |voice_module|
    voice_module.vendored_frameworks = "SDK/Voice/ZZKitVoice.xcframework"
    voice_module.frameworks = 'Foundation'
    voice_module.dependency 'ZZWidgets/Core'
  end

  s.subspec 'RUM' do |rum_module|
    rum_module.vendored_frameworks = "SDK/RUM/ZZKitRUM.xcframework"
    rum_module.frameworks = 'Foundation'
    rum_module.dependency 'ZZWidgets/Core'
  end

  s.subspec 'Log' do |log_module|
    log_module.vendored_frameworks = "SDK/Log/ZZKitLog.xcframework"
    log_module.frameworks = 'Foundation'
    log_module.dependency 'ZZWidgets/Core'
  end

end
