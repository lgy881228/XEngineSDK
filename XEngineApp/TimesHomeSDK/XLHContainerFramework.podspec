#
# Be sure to run `pod lib lint CLAAccount.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'XLHContainerFramework'
  s.version          = '1.0.0'
  s.summary          = 'A short description of XLHContainerFramework.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  iOS library for xlink restful request
DESC

  s.homepage         = 'http://XLHContainerFramework'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Copyright', :text => 'xlink.inc copyright' }
  s.author           = { 'app-generate' => 'guopeilun@xlink.cn' }
  s.source           = { :git => 'http://XLHContainerFramework', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  s.vendored_frameworks ='XLHContainerFramework/*.framework'
  s.resources = 'XLHContainerFramework/*.bundle'
  s.frameworks = 'Foundation'
  s.requires_arc = true  
  s.dependency 'dsBridge'
  #s.dependency 'UMengUShare/Social/ReducedWeChat'
  #s.dependency 'UMengUShare/Social/ReducedQQ'
  #s.dependency 'UMengUShare/Social/SMS'
  s.dependency 'WechatOpenSDK'
  
end
